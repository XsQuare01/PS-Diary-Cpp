# [Gold IV] Estimating the Flood Risk - 18211 

[문제 링크](https://www.acmicpc.net/problem/18211) 

### 성능 요약

메모리: 2044 KB, 시간: 0 ms

### 분류

너비 우선 탐색, 그래프 이론, 그래프 탐색, 구현

### 제출 일자

2024년 4월 19일 17:06:59

### 문제 설명

<p>Mr. Boat is the owner of a vast extent of land. As many typhoons have struck Japan this year, he became concerned of flood risk of his estate and he wants to know the average altitude of his land. The land is too vast to measure the altitude at many spots. As no steep slopes are in the estate, he thought that it would be enough to measure the altitudes at only a limited number of sites and then approximate the altitudes of the rest based on them.</p>

<p>Multiple approximations might be possible based on the same measurement results, in which case he wants to know the worst case, that is, one giving the lowest average altitude.</p>

<p>Mr. Boat’s estate, which has a rectangular shape, is divided into grid-aligned rectangular areas of the same size. Altitude measurements have been carried out in some of these areas, and the measurement results are now at hand. The altitudes of the remaining areas are to be approximated on the assumption that altitudes of two adjoining areas sharing an edge differ at most 1.</p>

<p>In the first sample given below, the land is divided into 5×4 areas. The altitudes of the areas at (1, 1) and (5, 4) are measured 10 and 3, respectively. In this case, the altitudes of all the areas are uniquely determined on the assumption that altitudes of adjoining areas differ at most 1.</p>

<p>In the second sample, there are multiple possibilities, among which one that gives the lowest average altitude should be considered.</p>

<p>In the third sample, no altitude assignments satisfy the assumption on altitude differences.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/11a1e0c5-c07f-48b6-b8bd-f8b787077fa9/-/preview/" style="width: 548px; height: 164px;"></p>

<p>Your job is to write a program that approximates the average altitude of his estate. To be precise, the program should compute the total of approximated and measured altitudes of all the mesh-divided areas. If two or more different approximations are possible, the program should compute the total with the severest approximation, that is, one giving the lowest total of the altitudes.</p>

### 입력 

 <p>The input consists of a single test case of the following format.</p>

<pre>w d n
x<sub>1</sub> y<sub>1</sub> z<sub>1</sub>
.
.
.
x<sub>n</sub> y<sub>n</sub> z<sub>n</sub></pre>

<p>Here, w, d, and n are integers between 1 and 50, inclusive. w and d are the numbers of areas in the two sides of the land. n is the number of areas where altitudes are measured. The i-th line of the following n lines contains three integers, x<sub>i</sub>, y<sub>i</sub>, and z<sub>i</sub> satisfying 1 ≤ x<sub>i</sub> ≤ w, 1 ≤ y<sub>i</sub> ≤ d, and −100 ≤ z<sub>i</sub> ≤ 100. They mean that the altitude of the area at (x<sub>i</sub>, y<sub>i</sub>) was measured to be z<sub>i</sub>. At most one measurement result is given for the same area, i.e., for i ≠ j, (x<sub>i</sub>, y<sub>i</sub>) ≠ (x<sub>j</sub>, y<sub>j</sub>).</p>

### 출력 

 <p>If all the unmeasured areas can be assigned their altitudes without any conflicts with the measured altitudes assuming that two adjoining areas have the altitude difference of at most 1, output an integer that is the total of the measured or approximated altitudes of all the areas. If more than one such altitude assignment is possible, output the minimum altitude total among the possible assignments.</p>

<p>If no altitude assignments satisfy the altitude difference assumption, output No.</p>

