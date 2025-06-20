Formula para achar o número de possibilidades de Binary Trees -- T(n) = 2n * Cn / (n + 1)
Altura da árvore binária -- 2 * n - 1



Se altura for dada:
Numero mínimo de nodes para formar uma árvore N -- N + 1
Numero máximo de nodes para formar uma árvore N -- 2^(h+1) - 1



Se quantidade de nodes for dada:
Altura mínima -- log(n+1) - 1
Altura máxima -- n - 1


Degree 1 = Degree 2 + 1 (Quantidade de nodes).
nodes externos = nodes internos + 1 (para um strict binary tree)


-------------------------------------------------------------------------------------------------

Em uma N-ary Tree:

Se a altura foir dada 
Altura minima -- N = mh + 1
Altura maxima -- N = m^(h+1) - 1 / m - 1



Se quantidade de nodes for dada:
Altura mínima --  h = logm[n(m - 1) + 1] - 1
Altura máxima --  h = n - 1 / m 


external nodes = (m-1)i + 1
internal nodes = i

