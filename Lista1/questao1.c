/*
Nome: Augusto Castilho
Matrícula: 54880
Lista: 1
Exercício: 1


    a) x: 10 (O valor de X se mantém)
    b) y: 20 (O valor de Y se mantém)
    c) &x: 1000 (Puxa o endereço de X, que é 1000)
    d) &y: 1004 (Puxa o endereço de Y, que é 1004)
    e) p1: 1004 (Apontou para o valor de X que é 1000, porém como havia um ((p1)+++) ele passou a apontar para o próximo endereço, que é 1004)
    f) p2: 1004 (Apontou para o valor de Y que é 1004)
    g) p1 + p2 = 40 (Como agora p1 está apontado para o mesmo endereço que p2 (1004), os valores buscados no endereço 1004 são somados, ou seja, 20 + 20 = 40)
    h) *(&x) = 10 (Está pegando o valor que está no endereço de X (1000), que é 10)
    i) &(*p2) = 1004 (O valor de p2 é 20, como está pedindo o endereço do valor, dá se o 1004)
 


*/