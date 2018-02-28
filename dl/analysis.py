from openpyxl import load_workbook
import numpy as np

#Load data from workbook
wb = load_workbook('DL03_Teste01_Dados.xlsx')
sheet = wb[u'Planilha1']

#Recover data
datasheet = []
for row in sheet.iter_rows(min_row=3, min_col=2):    
    newRow = list() 
    for cell in row:
       # print type(cell.value)
        newRow.append(cell.value)
    datasheet.append(tuple(newRow))
    
#Transpose matrix so we can calculate both covariance and correlation matrix
data = np.reshape( np.array(datasheet), (9, 683) )
covMatrix = np.cov(data)
corMatrix = np.corrcoef(data)

#Save data in file
datafile = open("analysis.txt", "w")
datafile.write("Original\n")
datafile.write("Covariance matrix: \n")
for i in range(covMatrix.shape[0]):
    datafile.write(str(covMatrix[i]))
    datafile.write('\n')
datafile.close()

datafile = open("analysis.txt", "a")
datafile.write("\nCorrelation matrix: \n")
for i in range(corMatrix.shape[0]):
    datafile.write(str(corMatrix[i]))
    datafile.write('\n')
datafile.close()

print "Done ;)\nBye"
