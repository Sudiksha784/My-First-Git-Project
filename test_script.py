import requests

def test_dependency():
    response = requests.get(
        "https://example.com",
        timeout=15
    )
    assert response.status_code == 200
    print("Dependency test passed!")

if __name__ == "__main__":
    test_dependency()

