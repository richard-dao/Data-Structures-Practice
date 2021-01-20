# Python

# 1. Invert a Dictionary
# Example:
# {"cat": 4, "bird": 2} -> {4: {"cat"}, 2: {"bird"}}
# {"cat": 4, "dog": 4, "bird": 2} -> {4: {"cat", "dog"}, 2: {"bird"}}

def dict_inv(d):
    # YOUR CODE HERE
    inv_dict = {}
    for x,y in d.items():
    # x = keys
    # y = values
        if (y in inv_dict):
            inv_dict[y] |= {x}
        else:
            inv_dict[y] = {x}
    return inv_dict
    
    
# 2. Count Elements in List of Sets
# [{"a", "b", "c"}, {"c", "d"}] -> {"a": 1, "b": 1, "c": 2, "d": 1}

def count_occurrences(set_list):
    # YOUR CODE HERE
    out_dict = {}
    for x in set_list:
      for y in x:
        if (y in out_dict):
          out_dict[y] += 1
        else:
          out_dict[y] = 1
    return out_dict 

# 3. Set With At Least n or More Occurences
# [{"a", "b", "c"}, {"c", "d"}], n = 2 -> {"c"}
# [{"a", "b", "c"}, {"c", "d"}], n = 3 -> {}
# [{"a", "b", "c"}, {"c", "d"}], n = -1 -> {"a", "b", "c", "d"}

def at_least(n, set_list):
    # YOUR CODE HERE
    occur_dict = count_occurrences(set_list)
    r_set = set()
    for x,y in occur_dict.items():
      if (occur_dict[x] >= n):
        r_set.add(x)
    return r_set
