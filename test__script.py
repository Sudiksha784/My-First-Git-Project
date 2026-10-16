
def add(a, b):
    return a + b

def test_add():
    assert add(2, 3) == 5
    assert add(10, 20) == 30
    print("All tests passed successfully!")

if __name__ == "__main__":
    test_add()
