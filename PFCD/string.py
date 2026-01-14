# ===============================
# MINOR ASSIGNMENT 7 - STRINGS
# Python for CS & DS
# ===============================

# 1 Replace repeated characters
def replace_repeat(s):
    res = s[0]
    for i in range(1,len(s)):
        if s[i]==s[i-1]:
            res += "*"
        else:
            res += s[i]
    return res
print("1:", replace_repeat("balloon"))

# 2 Anagram
def is_anagram(a,b):
    return sorted(a)==sorted(b)
print("2:", is_anagram("listen","silent"))

# 3 Word count
def word_count(s):
    return len(s.split())
print("3:", word_count("Python is powerful"))

# 4 Character count
s="hello"
print("4:", s.count("l"))

# 5 Longest word length
s="Python is very powerful"
print("5:", len(max(s.split(), key=len)))

# 6 Replace vowels
def replace_vowel(s):
    v="aeiou"
    res=""
    for c in s:
        if c in v:
            res+=v[(v.index(c)+1)%5]
        else:
            res+=c
    return res
print("6:", replace_vowel("hello"))

# 7 Rotational palindrome
def rotational_palindrome(s):
    for i in range(len(s)):
        r=s[i:]+s[:i]
        if r==r[::-1]:
            return True
    return False
print("7:", rotational_palindrome("aab"))

# 8 Valid URL
import re
print("8:", bool(re.match(r'https?://\S+', "https://google.com")))

# 9 Vowels and consonants
s="hello world"
v=c=0
for ch in s:
    if ch.isalpha():
        if ch in "aeiouAEIOU": v+=1
        else: c+=1
print("9:", v, c)

# 10 Reverse tokens
s="Python is easy"
print("10:", s.split()[::-1])

# 11 Words starting b ending d
s="big bad bold bird band"
print("11:")
for w in s.split():
    if w.startswith("b") and w.endswith("d"):
        print(w)

# 12 Three letter combinations
import itertools
word="bathe"
print("12:", ["".join(p) for p in itertools.permutations(word,3)])

# 13 Remove extra spaces
s="Hello   World"
print("13:", " ".join(s.split()))

# 14 Reverse middle half
s="abcdefgh"
n=len(s)
print("14:", s[:n//4]+s[n//4:3*n//4][::-1]+s[3*n//4:])

# 15 Substring frequency
from itertools import groupby
s="aabbbccccddddd"
print("15:")
for k,g in groupby(s):
    g="".join(g)
    if len(g)==3:
        print(g)


# 16 Unique sorted characters
s="banana"
print("16:", "".join(sorted(set(s))))

# 17 Outputs
s="how now brown cow"
print("17a:", s[s.find('o'):s.rfind('o')])
print("17b:", chr(ord('A')+2)+chr(ord('Z')-3))
s="abc123def456ghi789"
indices=[i for i,c in enumerate(s) if c=="3"]
print("17c:", s)
s="abracadabra"
print("17d:", s.replace(s[s.find('a'):s.find('r')],"XYZ"))
s="hello"
shift=2
print("17e:", "".join(chr((ord(c)-97+shift)%26+97) for c in s))
s="mississippi"
print("17f:", "".join(sorted(set(s))))

# 18 Quote outputs
quote="The quick brown fox jumps over the lazy dog"
print("18a:", quote.upper())
print("18b:", quote[::-1])
print("18c:", quote[4:19])
print("18d:", quote.replace("fox","cat"))
print("18e:", quote.count("o"))
print("18f:", quote.startswith("The"))
print("18g:", "brown" in quote)
print("18h:", quote.islower())

# 19 Quote functions
quote="Knowledge is power. Power is gained through knowledge."
print("19a:", quote.find("power"))
print("19b:", quote.rfind("knowledge"))
print("19c:", quote.title())
print("19d:", quote.lower())
print("19e:", quote.upper())
print("19f:", quote.endswith("knowledge."))
print("19g:", quote.split(" "))
print("19h:", quote.partition("is"))
print("19i:", quote.isalpha())

# 20 Regex patterns
import re
string1="Python Programming Language"
print("20a:", re.search(". m?", string1).group())
print("20b:", re.search(".*Language$", string1).group())
print("20c:", re.search(" w* s w*", string1))
print("20d:", re.search(".*", string1).group())

# 21 Regex outputs
print("21a:", re.fullmatch(r"[A-Za-z]*", string1))
print("21b:", re.sub("Programming","Coding",string1))
print("21c:", re.split(r"\s+",string1))
print("21d:", re.findall(r"\w+",string1))

# 22 Symmetric / Asymmetric
s="abab"
print("22:", "Symmetric" if s[:len(s)//2]==s[len(s)//2:] else "Asymmetric")

# 23 Delete ith index
s="python"
i=2
print("23:", s[:i]+s[i+1:])

# 24 Secure password regex
pattern=r'(?=.*[A-Z])(?=.*[a-z])(?=.*\d)(?=.*[!@#$%&*?]).{8,}'
print("24: Regex Pattern Ready")

# 25 Regex counting
s="Hello 123"
print("25 digits:", len(re.findall(r"\d",s)))
print("25 non-digits:", len(re.findall(r"\D",s)))
print("25 spaces:", len(re.findall(r"\s",s)))
print("25 words:", len(re.findall(r"\w+",s)))
