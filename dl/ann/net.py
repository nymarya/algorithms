from openpyxl import load_workbook
import numpy as np
from sklearn.decomposition import PCA
import cov
import math
import read

data = read.read()

data_training = data[0]
y_training = np.array([ 1 if i==2 else 0 for i in data[1]])
data_test = data[2]
y_test = np.array([ 1 if i==2 else 0 for i in data[3]])


from sklearn.preprocessing import StandardScaler
train_data_std = StandardScaler().fit_transform(data_training)

#get covariance matrix
#egenvalues and eigenvectors
cov_mat = np.cov(train_data_std.T)
eig_vals, eig_vecs = np.linalg.eig(cov_mat)

for ev in eig_vecs:
    np.testing.assert_array_almost_equal(1.0, np.linalg.norm(ev))

# Make a list of (eigenvalue, eigenvector) tuples
eig_pairs = [(np.abs(eig_vals[i]), eig_vecs[:,i]) for i in range(len(eig_vals))]

# Sort the (eigenvalue, eigenvector) tuples from high to low
eig_pairs.sort()
eig_pairs.reverse()

#reduce the dimension

matrix_w = np.hstack((eig_pairs[0][1].reshape(9,1), 
                      eig_pairs[1][1].reshape(9,1),
                      eig_pairs[2][1].reshape(9,1), 
                      eig_pairs[3][1].reshape(9,1),
                      eig_pairs[4][1].reshape(9,1), 
                      eig_pairs[5][1].reshape(9,1),
                      eig_pairs[6][1].reshape(9,1),
                      ))
                      

X_training= train_data_std.dot(matrix_w).astype('float32')
  
test_data_std = StandardScaler().fit_transform(data_test)
X_test = test_data_std.dot(matrix_w)


#create 3 layers with 30 neurons each
from sklearn.neural_network import MLPClassifier
mlp = MLPClassifier(hidden_layer_sizes=(50, 100), batch_size=100)

# #############################################################################
# Compute train and test errors
alphas = np.logspace(-5, 1)
train_errors = list()
test_errors = list()
cont = 0 
for alpha in alphas:
    mlp.set_params(alpha=alpha)
    mlp.fit(X_training, y_training.transpose())
    train_errors.append(1 - mlp.score( X_training, y_training.transpose()))
    test_errors.append(1- mlp.score(X_test, y_test.transpose()))

i_alpha_optim = np.argmax(test_errors)
alpha_optim = alphas[i_alpha_optim]
print("Optimal regularization parameter : %s" % alpha_optim)
print(train_errors)
print(test_errors)

#teste
#prediction
predictions = mlp.predict(X_test)

#prin confusion matrix
from sklearn.metrics import classification_report,confusion_matrix
confusion = confusion_matrix(y_test,predictions)
print(confusion)

print(classification_report(y_test,predictions))
from sklearn.metrics import mean_squared_error
print (mean_squared_error(y_test, predictions))
# fp_ratio = fpcount
# fn_ratio =
fp = confusion[0][1]
fn = confusion[1][0]
tp = confusion[1][1]
tn = confusion[0][0]
fpr = fp / (tn + fp)
fnr = fn / (tp + fn)
print("fpr: ", fpr)
print("fnr: ", fnr)

accuracy = (tp + tn) /(tp + tn+fp+fn)
print("ac: ", accuracy)
print(predictions)
