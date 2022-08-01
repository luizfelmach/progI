srcFile=snake.c

gcc --std=gnu89 $srcFile -o snake -lm

for subfolder in ./testes/*
do
    for testFolder in $subfolder/*
    do
        rm -r $testFolder/saida/
        mkdir $testFolder/saida
        ./snake $testFolder/mapa.txt < $testFolder/movimentos.txt > $testFolder/saida/saida.txt
    done
done

diff -r testes/ gabarito/
