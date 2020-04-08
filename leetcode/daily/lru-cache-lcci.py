class LRUCache:
    def __init__(self, capacity: int):
        self.capacity = capacity
        self.tasks = []

    def get(self, key: int) -> int:
        for task in self.tasks:
            if key in task:
                self.tasks.remove(task)
                self.tasks.append(task)
                return task[key]
        return -1

    def put(self, key: int, value: int) -> None:
        for task in self.tasks:
            if key in task:
                self.tasks.remove(task)
                task[key] = value
                self.tasks.append(task)
                return
        if len(self.tasks) == self.capacity:
            self.tasks.pop(0)
        self.tasks.append({key: value})


# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)


if __name__ == "__main__":
    cache = LRUCache(2)
    cache.put(1, 1)
    cache.put(2, 2)
    print(cache.get(1))
    cache.put(3, 3)
    print(cache.get(2))
    cache.put(4, 4)
    print(cache.get(1))
    print(cache.get(3))
    print(cache.get(4))
