# Dicotomia
Dicotomia é um método numérico usado para encontrar a raiz de uma equação que exista dentro de um limite A B.
Consiste em aplicar A, B e M (Média de A e B) como x da função, comparar os valores e atualizar o número que não mudou o sinal.

Ex.: a função f(x) = x³ - x - 1 não pode ser facilmente resolvida, porém, dando à ela os limites de A = 1, B = 2 e Erro = 0,03

a	m	b	f(a)	f(m)	f(b)
1,000	1,500	2,000	-1,000	0,875	5,000
1,000	1,250	1,500	-1,000	-0,297	0,875
1,250	1,375	1,500	-0,297	0,225	0,875
1,250	1,313	1,375	-0,297	-0,052	0,225
1,313	1,344	1,375	-0,049	0,084	0,225
1,313	1,329	1,344	-0,049	0,016	0,084
![image](https://user-images.githubusercontent.com/6143348/111341459-4ce12680-8658-11eb-8f26-4b29cd5e44a3.png)

Podemos afimar que o zero real da função f(x) é 1,329, com erro de aprox +/- 0,016					


