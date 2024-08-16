# Solução Jantar dos Filósofos
Para resolver o problema, implementei um semáforo associado a cada hashi, para garantir que apenas um filósofo possa pegar o hashi de cada vez. Defini o valor inicial do semáforo como 1, com a intenção de indicar que o hashi está disponível.
Depois, usei um semáforo adicional (`mutex`) para garantir que, ao pegar os hashis, nenhum outro filósofo possa interromper. Evitando condições de deadlock, onde todos os filósofos poderiam pegar um hashi e esperar indefinidamente pelo segundo.
Dessa forma, cada filósofo é uma thread separada que alterna entre pensar e comer. Quando ele deseja comer, ele tenta pegar os dois hashis adjacentes. Se conseguir, ele come, e depois libera os hashis.
A finalidade do uso do semáforo `mutex` foi para controlar o acesso à região crítica evitando que todos os filósofos peguem um hashi e fiquem bloqueados esperando pelo outro. Isso assegura que pelo menos um filósofo consiga pegar os dois hashis e comer.
Como os filósofos pegam os hashis em ordem e não há uma espera indefinida, o sistema evita a inanição, garantindo que todos em algum momento consigam comer.

