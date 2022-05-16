# target-subset

This is a Leetcode-style problem related to binary encoding and decoding. The goal is to take in a sorted array of integers and a target integer, then find a multiset that is a subset of the input array whose elements sum to the target integer. There is also an emphasis put on using larger elements from the input array, to minimize the size of the subset.

For example, say the input is [2,5,6] and target=12.

One solution would be [6,6]. But, another solution is [2,2,2,2,2,2] However, the first multiset is preferable because it is smaller.
