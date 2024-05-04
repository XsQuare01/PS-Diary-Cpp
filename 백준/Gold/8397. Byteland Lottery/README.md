# [Gold III] Byteland Lottery - 8397 

[문제 링크](https://www.acmicpc.net/problem/8397) 

### 성능 요약

메모리: 5928 KB, 시간: 144 ms

### 분류

조합론, 수학, 정수론

### 제출 일자

2024년 5월 4일 16:46:37

### 문제 설명

<p>One of the most popular games organized by Byteland Lottery is "Huge blend". The rules of this game are simple. From the container with a fixed number of balls in it (each of them has a natural number assigned), some number of balls are chosen. In the next step the product of all numbers from the chosen balls is calculated. That product is the winning number. The person who guesses the right number wins the main prize. Before the drawing, it is known how many balls will take part in it. The numbers written on the balls are also known. It is not known however, how many balls will be selected - maybe all of them, or maybe only one.</p>

<p>ByteGuy always wanted to win "Huge blend", however years of fruitless attempts caused that he started to wonder about the chances of winning. He decided to count the number <em>n</em> - the sum of all possible results of draws. Unfortunately, ByteGuy's computer overheated during calculations, so he asked you to help him calculate something simpler - the value of <em>F</em>(<em>n</em>), where <em>F</em> is a function defined as follows:</p>

<ul>
	<li><em>F</em>(<em>k</em>) = <em>k</em>, <em>k</em> ≤ 9</li>
	<li><em>F</em>(<em>k</em>) = <em>F</em>(the sum of all digits of <em>k</em>), <em>k</em> ≥ 10</li>
</ul>

<p>For example: F(9) = 9, F(123) = 6, F(9876) = F(30) = 3.</p>

<p>Write a program which:</p>

<ul>
	<li>reads from the standard input the number <em>l</em> (the number of balls taking part in a draw) and <em>l</em> natural numbers <em>w</em><sub>1</sub>, <em>w</em><sub>2</sub>, ..., <em>w<sub>l</sub></em> (numbers printed on the balls),</li>
	<li>computes the value of <em>F</em>(<em>n</em>), where <em>n</em> is the sum of all possible results of draws,</li>
	<li>writes the answer to the standard output.</li>
</ul>

### 입력 

 <p>The first line of the standard input contains a natural number <em>l</em> - the number of balls taking part in a draw, 1 ≤ <em>l</em> ≤ 10<sup>6</sup>. In the second line there are <em>l</em> natural numbers <em>w<sub>m</sub></em>, 0 ≤ <em>w<sub>m</sub></em> ≤ 10<sup>8</sup> - numbers written on the balls. They are separated with single spaces.</p>

### 출력 

 <p>One integer is to be written to the standard output. This integer should be the value of <em>F</em>(<em>n</em>).</p>

