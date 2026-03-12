// This file is for documentation purposes only. It will be ignored by the compiler.
// Our Teaching Assistant will manually grade this file.


// Please make sure that you include the entire content of this file as comments.


/* Design Doc: communicate your thought process in English.
 
-------------Problem analysis and algorithm design------------
Answer the following questions for each of the following functions: (1) operator<= for TokenFreq objects,  (2) operator+ for TokenFreq objects, (3) getTokenFreqVec(), and (4) the sorting function  (you only need to do one. pick either one):




1. What's the input data of this problem?
2. What's the output data of this problem?
3. List two sample inputs and their corresponding outputs
4. For the getTokenFreq() only, what's your algorithm? Please describe your algorithm in pseudocode.
5. Apply the above 2 sample inputs to your getTokenFreqVec() algorithm, does your algorithm produce the expected outputs?
6. For the getTokenFreq() only: what's the time complexity of your algorithm?


------------Implementation strategies in C++: example questions----------------------
7. What built-in and/or user-defined data types are you going to use and why?
8. What will be the function prototype of the overloaded operator<= and operator+?  
*/

/*
=======================
My Design Doc Responses
=======================

Function (1): operator<= for TokenFreq objects
1) Input data:
	- Two TokenFreq objects, each has a token (string) and freq (int).
2) Output data:
	- A bool indicating whether lhs should be considered <= rhs.
3) Two sample inputs and outputs:
	- Input: lhs={"apple",2}, rhs={"banana",1} -> Output: true ("apple" < "banana")
	- Input: lhs={"cat",7}, rhs={"cat",3} -> Output: false (same token, 7 <= 3 is false)
4) Time complexity:
	- O(1) for fixed-size comparisons of fields (practically constant-time per object compare).

Function (2): operator+ for TokenFreq objects
1) Input data:
	- Two TokenFreq objects.
2) Output data:
	- A new TokenFreq object.
3) Two sample inputs and outputs:
	- Input: {"dog",3} + {"dog",4} -> Output: {"dog",7}
	- Input: {"left",10} + {"right",5} -> Output: {"left",10} (different token policy)
4) Time complexity:
	- O(1), because it performs one token check and at most one integer addition.

Function (3): getTokenFreqVec()
1) Input data:
	- A vector<string> tokens.
2) Output data:
	- A vector<TokenFreq> where each distinct token appears once with its count.
3) Two sample inputs and outputs:
	- Input: ["a","b","a","c","b","a"]
	  Output: [{"a",3},{"b",2},{"c",1}] (order can vary before sorting)
	- Input: []
	  Output: []
4) Algorithm in pseudocode:
	- create empty hash map freqMap<string,int>
	- for each token t in tokens:
		 freqMap[t] = freqMap[t] + 1
	- create empty vector<TokenFreq> result
	- for each (token, count) pair in freqMap:
		 append TokenFreq{token, count} to result
	- return result
5) Apply above sample inputs:
	- For ["a","b","a","c","b","a"], map becomes {a:3,b:2,c:1}, vector has exactly those pairs.
	- For [], loop does nothing, map stays empty, output vector is empty.
	- Yes, algorithm produces expected outputs.
6) Time complexity:
	- Average case O(n), where n is number of input tokens.
	- Counting loop is O(n), conversion loop is O(k), k <= n, so total O(n).

Function (4): sorting function (chosen: sortByFreqDescThenTokenAsc)
1) Input data:
	- A vector<TokenFreq> by reference.
2) Output data:
	- Same vector sorted by freq descending, tie by token ascending.
3) Two sample inputs and outputs:
	- Input: [{"a",1},{"b",3},{"c",2}] -> Output: [{"b",3},{"c",2},{"a",1}]
	- Input: [{"z",5},{"a",5},{"m",5}] -> Output: [{"a",5},{"m",5},{"z",5}]
4) Time complexity:
	- O(k log k), where k is the number of TokenFreq elements in the vector.
	- This is the standard complexity of comparison-based sorting (`sort`).

Q7) Built-in and/or user-defined data types and why:
	- string: to store each token text.
	- int: to store occurrence counts.
	- vector<string>: input sequence of tokens.
	- vector<TokenFreq>: compact output of unique tokens + frequencies.
	- unordered_map<string,int>: efficient average O(1) counting.
	- struct TokenFreq: user-defined type grouping token and frequency cleanly.

Q8) Function prototypes of overloaded operators:
	- bool operator<=(const TokenFreq& lhs, const TokenFreq& rhs);
	- TokenFreq operator+(const TokenFreq& lhs, const TokenFreq& rhs);
*/


/*
-----------Code Review by yourself as you are coding and after you finish coding ----------------
1. Have you included comments to enhance your code's readability?
2. Have you included three distinct test cases (negative and positive cases) in your own unit tests?
3. Have  you hard-coded the input and output pair to “fool” the unit tests?  (The correct answer is “No, I value academic integrity.”)
4. Have you followed these core guidelines ((find the URL on iLearn))
*/

/*
My Code Review Answers:
1) Yes. I added explanatory comments in the implementation files and unit tests to improve readability,
	including plain-English comments for non-coders.

2) Yes. I included three distinct test cases for each required function:
	- matrixInit()
	- operator<=
	- operator+
	- getTokenFreqVec()
	- sortByTokenAsc()
	- sortByFreqDescThenTokenAsc()
	The tests include both positive and edge/negative-style cases (for example, invalid matrix dimensions
	and empty input vectors).

3) No, I value academic integrity. I did not hard-code input/output pairs to pass tests.
	The functions are implemented generally and evaluated by multiple independent test inputs.

4) Yes. I followed the core guidelines by:
	- keeping code modular with header/source separation,
	- using clear naming and consistent formatting,
	- writing readable comments,
	- implementing required functionality without unnecessary complexity,
	- validating behavior using unit tests and successful compilation.
*/