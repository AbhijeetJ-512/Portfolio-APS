document1 = "hello abhijeet"
document2 = "hello"


tokens1 = document1.lower().split()
tokens2 = document2.lower().split()


terms = list(set(tokens1 + tokens2))

inverted_index = {}

for term in terms:
	documents = []
	if term in tokens1:
		documents.append("Document 1")
	if term in tokens2:
		documents.append("Document 2")
	inverted_index[term] = documents
for term, documents in inverted_index.items():
	print(term, "->", ", ".join(documents))
