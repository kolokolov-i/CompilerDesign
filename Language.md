Программа: главная программа языка С++. Допускается описание структур.
Типы данных: double, int (знаковые и беззнаковые).
Операции: арифметические и сравнения.
Операторы: присваивания и while.
Операнды:  простые переменные, элементы структур  и  константы.
Константы: символьные и целые в 10 c/c .

Gc:

```
<программа> => <описания> <функция_main>
<описания> => <описания> <описание> | ε
<описание> => <описание_данных> | <описание_структуры>
<описание_данных> => <тип> <список_ид> ;
<тип> => unsigned int | signed int | int | double | char | <ID>
<список_ид> => <список_ид>, <ID> | <список_ид> , <присваивание> | <присваивание> | <ID>
<описание_структуры> => struct <ID> { <элементы_структуры> } ;
<элементы_структуры> => <элементы_структуры> <описание_данных> | ε
<имя> => <имя> . <ID> | <ID>
<функция_main> => void main ( <список_параметров> ) { <блок> }
<список_параметров> => <список_параметров> , <тип> <ID> | <тип> <ID>
<блок> => <блок> <описание_данных> | <блок> <оператор> | ε
<оператор> => <цикл> | <присваивание> | <A1> | { <блок> } | ;
<цикл> => while ( <A1> ) <оператор>
<присваивание> => <имя> = <A1>
<A1> => <A1> == <A2> | <A1> != <A2> | <A2>
<A2> => <A2> < <A3> | <A2> <= <A3> | <A2> > <A3> | <A2> >= <A3> | <A3>
<A3> => <A3> + <A4> | <A3> - <A4> | <A4>
<A4> => <A4> * <A5> | <A4> / <A5> | <A4> % <A5> | <A5>
<A5> => <имя> | <CONST> | ( <A1> )
<ID> => <буква> <окончание>
<окончание> => <окончание> <буква> | <окончание> <цифра> | ε
<CONST> => <конст_цел> | <конст_вещ> | <конст_эксп> | <конст_симв>
<конст_цел> => <конст_цел> <цифра> | <цифра>
<конст_вещ> => <конст_цел> . <конст_цел> | . <конст_цел> | <конст_цел> .
<конст_эксп> => <конст_цел> <экспонента> | <конст_вещ> <экспонента>
<экспонента> => E <знак> <конст_цел>
<знак> => + | - | ε
<цифра> => 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9
<буква> => a | b | c | ... | z | _
<символы> => <буква> | <цифра> | ...
```