#K = reais

##Resolucao da letra a
# @param container Lista de vetores
# @param key Elemento pertencente a K
def sublista(container, key):
    result = list()
    for i in container:
        if(i[len(i)-1] == key):
            list.append(i)
            
    return result
      
##Resolucao da letra b
# @param container Lista de vetores
def soma(container):
    #Cria vetor que guarda a soma
    result = container[0]
    #Percorre a lista
    for j in range(len(container[0])):
        sum = 0
        # Soma os vetores
        for k in range(len(container)):
            sum += container[k][j]

        # Guarda a soma no vetor auxiliar
        result[j] = sum
    
    return result
    
    
##Resolucao da letra b
# @param container Lista de vetores
# @param key Elemento pertencente a K
def somaSublistas(container, key):
    #Cria vetor que guarda a soma
    result = container[0]
    
    # Recupera sublistas
    sublists = sublista(container, key)
    #Percorre a lista
    for j in range(len(sublists[0])):
        sum = 0
        # Soma os vetores
        for k in range(len(sublists)):
            sum += sublists[k][j]

        # Guarda a soma no vetor auxiliar
        result[j] = sum
    
    return result
  
n_list = list()
k = float(input("Digite o elemento k:"))

num = int(input("Digite o tamanho do vetor:"))
n = input("Elemento:")

while (n != ''):
    array = []
    for i in range(num):
        array.append(float(n))
        n = input("Elemento :")
    n_list.append(array)
  

print("##### QUESTAO 1 #####")
resultado = sublista(n_list, k)
print( resultado )
print("##### QUESTAO 2 #####")
resultado = soma(n_list)
print(resultado)
print("##### QUESTAO 2 #####")
resultado = soma(n_list)
print(resultado)
