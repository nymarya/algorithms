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
    
data = np.array(datasheet)
covMatrix = np.cov(data)

#Save data in file
datafile = open("analysis.txt", "w")
datafile.write("Original\n")
datafile.write("Covariance matrix: \n")
for i in np.nditer(covMatrix.T):
    print i
datafile.close()

print "Done ;)\nBye"
#print np.array([(881092, 9.3),(729387,8.0)], dtype='>i4, float')
