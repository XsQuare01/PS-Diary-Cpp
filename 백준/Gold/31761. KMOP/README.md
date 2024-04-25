# [Gold V] KMOP - 31761 

[문제 링크](https://www.acmicpc.net/problem/31761) 

### 성능 요약

메모리: 34932 KB, 시간: 104 ms

### 분류

다이나믹 프로그래밍, 문자열

### 제출 일자

2024년 4월 25일 18:35:55

### 문제 설명

<p>You probably know the KMP algorithm. You may also know that “<code>KMP</code>” is an acronym that stands for “<code>Knuth Morris Pratt</code>”, who jointly published the algorithm in 1977. How do you pronounce “<code>KMP</code>”? Of course, you can just say “<code>Knuth Morris Pratt</code>”, but what about pronouncing the acronym itself? Since “<code>KMP</code>” is not a pronounceable word, you are forced to say the letters one by one. In this problem we are interested in pronounceable acronyms.</p>

<p>We need a few definitions to formalize the requirement. A phrase is a list of words and a word is a sequence of letters. Each letter is either a vowel or a consonant. Deciding whether a letter is a vowel or a consonant depends on the language and other elements. For simplicity, we say that the six letters “<code>A</code>”, “<code>E</code>”, “<code>I</code>”, “<code>O</code>”, “<code>U</code>” and “<code>Y</code>” are vowels, while all the rest are consonants. Although it is debatable whether a given word is pronounceable, we say that a word is pronounceable when it does not contain more than two contiguous consonants. For instance, “<code>LEMPEL</code>” is a pronounceable word, while “<code>DIJKSTRA</code>” is not.</p>

<p>Given a phrase composed of <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container> words, an acronym for the phrase is the concatenation of N prefixes, one prefix for each word, in the order they appear in the phrase. Each prefix must have at least one and at most three letters. Your task is to determine the minimum length a pronounceable acronym can have.</p>

<p>As an example with <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c3D"></mjx-c></mjx-mo><mjx-mn class="mjx-n" space="4"><mjx-c class="mjx-c33"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi><mo>=</mo><mn>3</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N = 3$</span></mjx-container> consider the phrase “<code>KNUTH MORRIS PRATT</code>”. There are <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c32"></mjx-c><mjx-c class="mjx-c37"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>27</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$27$</span></mjx-container> possible acronyms for this phrase, such as “<code>KMP</code>”, “<code>KMPR</code>”, “<code>KMPRA</code>”, “<code>KMOP</code>”, “<code>KMOPR</code>” and “<code>KNUMORPRA</code>”, among others. Some of these acronyms are pronounceable (“<code>KMOP</code>” and “<code>KMOPR</code>”), while some others not (“<code>KMP</code>”, “<code>KMPR</code>”, “<code>KMPRA</code>” and “<code>KNUMORPRA</code>”). Since the only three-letter acronym “<code>KMP</code>” is not pronounceable, it follows that “<code>KMOP</code>” is a minimum-length pronounceable acronym for the phrase.</p>

### 입력 

 <p>The first line contains a positive integer <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container> indicating the number of words in the phrase.</p>

<p>Each of the next <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container> lines contains a non-empty string made of uppercase letters representing a word in the phrase. Words are given in the order they appear in the phrase. The sum of the lengths of all the strings is at most <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-msup><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c><mjx-c class="mjx-c30"></mjx-c></mjx-mn><mjx-script style="vertical-align: 0.393em;"><mjx-mn class="mjx-n" size="s"><mjx-c class="mjx-c36"></mjx-c></mjx-mn></mjx-script></mjx-msup></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><msup><mn>10</mn><mn>6</mn></msup></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$10^6$</span></mjx-container>.</p>

### 출력 

 <p>Output a single line with an integer indicating the minimum length a pronounceable acronym can have, or the character “<code>*</code>” (asterisk) if no pronounceable acronym exists for the phrase.</p>

