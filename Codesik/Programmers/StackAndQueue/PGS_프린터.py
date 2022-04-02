class Document:
    priority: int
    location: int

    def __init__(self, priority, location):
        self.priority = priority
        self.location = location

    def __repr__(self):
        return f"({self.priority},{self.location})"

    def is_lower(self, other):
        return self.priority < other

def solution(priorities, location):
    s = []

    for index, p in enumerate(priorities):
        s.append(Document(p, index))

    printed = []

    while s:
        document = s.pop(0)
        has_higher_priority = False

        for el in s:
            if document.is_lower(el.priority):
                s.append(document)
                has_higher_priority = True
                break

        if not has_higher_priority:
            printed.append(document)

    for index, d in enumerate(printed):
        if d.location == location:
            return index + 1