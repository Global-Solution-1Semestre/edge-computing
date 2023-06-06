# edge-computing

Detalhes do projeto:
 O projeto é um sensor IoT que se comunicará com a nossa AI, Nix, onde esses sensores pegarão dados de blocos de plantas especifícas (morango, tomate, alface, hortelã, pimenta etc.). Esses dados serão mandados para 
 a Nix, para que ela possa fazer a análise e tomar decisões conforme os dados e histórico passado. Para simular a Nix, fizemos uma análise básica, com apenas dois estados e 3 valores (ruim e bom; umidade, temperatura
 e intensidade de luz). No projeto, utilizamos o sensor TMP para temperatura, um potenciometro para simular a umidade e um photoresistor para a luz, em conjunto com o circuito de LCD para o display, simulando a tela
 que o nosso projeto teria. Como o tinkercad é limitado, assim como o Arduino, não conseguimos colocar muito mais complexidade, como teria que ser feito em uma situação real, monitarando pestes, padrões de plantas,
 e possibilidade de infestações e doenças, visto que esse é o foco do nosso projeto, diminuir a colheita perdida por pestes e doenças, que pode chegar em até 40% da colheita total. Os valores são analisados a cada 
 começo do loop (antes de mostrar o estado do morango), então caso a mudança seja feito no meio da análise de dados, o novo valor sera contado apenas no começo do próximo loop, assim como o debug que é mostrado 
 somente no final de cada loop.
 
 Instruções de uso:
 A utilização do projeto é simples. Execute o código e altere os valores de temperauta, umidade e intensidade da luz que o próprio código fará a análise e retornará se a planta está viavél para o processamento, ou 
 se é necessário algum ajuste. 
 
Requisitos:
São necessário os sensores TMP, Photoresistor e um potênciometro, ou um DHT11, em conjunto com o circuito de fios, lcd, e placa Arduino. O ideal seria cada sensor para cada bloco de plantação, visto que plantas exigem
diferente tipos de ambientes para serem plantadas.

Dependências:
O projeto depende de sensores funcionando em tempo real e da sua precisão, sendo que qualquer erro pode acarretar na AI fazer a análise errada e tomar decisões que podem prejudicar a plantação. Outra dependência são
a vida útil dos sensores e camerâs, que também são um fator vital para a análise de padrões de plantas e de comportamento de possíveis invasores, vírus ou doenças. Uma boa comunicação IoT, dos sensores com a central
de controle da AI também é essencial para o bom funcionamento e tratamento de erros dentro da plantação. Uma falha nisso e um fungo ou uma peste pode acabar com toda a plantação. Os valores utilizados no projeto
são relativos e podem mudar, pois isso é uma simulação no TinkerCad e os valores para a vida real variam bastante. 
