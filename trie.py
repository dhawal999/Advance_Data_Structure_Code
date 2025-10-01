# filename: trie.py
# Run: python trie.py

class TrieNode:
    def __init__(self):
        self.children = {}
        self.is_end = False

class Trie:
    def __init__(self):
        self.root = TrieNode()

    def insert(self, word: str):
        node = self.root
        for ch in word:
            if ch not in node.children:
                node.children[ch] = TrieNode()
            node = node.children[ch]
        node.is_end = True

    def search(self, word: str) -> bool:
        node = self.root
        for ch in word:
            if ch not in node.children:
                return False
            node = node.children[ch]
        return node.is_end

    def starts_with(self, prefix: str) -> bool:
        node = self.root
        for ch in prefix:
            if ch not in node.children:
                return False
            node = node.children[ch]
        return True

if __name__ == "__main__":
    t = Trie()
    words = ["hello", "helium", "hero", "her", "help"]
    for w in words: t.insert(w)
    tests = ["hero", "her", "he", "helped", "hello"]
    for s in tests:
        print(f"{s}: search={t.search(s)}, starts_with={t.starts_with(s)}")

