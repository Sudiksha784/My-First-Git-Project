# Experiment B: Create Multiple Jobs and Define Execution Order

## Aim
To create a GitHub Actions workflow containing multiple jobs and control their execution order using the `needs` keyword.

## Procedure

1. Open your GitHub repository.
2. Select **Add file → Create new file**.
3. Enter the path `.github/workflows/multiple-jobs.yml`.
4. Paste the following code:

```yaml
name: Multiple Jobs Workflow

on:
  push:
    branches: [main]
  workflow_dispatch:

jobs:
  build:
    name: Build Job
    runs-on: ubuntu-latest

    steps:
      - name: Display build message
        run: echo "Build completed successfully"

  test:
    name: Test Job
    runs-on: ubuntu-latest
    needs: build

    steps:
      - name: Display test message
        run: echo "Testing completed successfully"

  deploy:
    name: Deploy Job
    runs-on: ubuntu-latest
    needs: test

    steps:
      - name: Display deployment message
        run: echo "Deployment completed successfully"
```

5. Click **Commit changes** and commit the file to `main`.
6. Open the **Actions** tab.
7. Select **Multiple Jobs Workflow**.
8. Open the latest run and inspect the job diagram and logs.

## Explanation

- `build` runs first because it has no dependencies.
- `test` runs only after `build` succeeds because it contains `needs: build`.
- `deploy` runs only after `test` succeeds because it contains `needs: test`.
- If an earlier required job fails, dependent jobs are normally skipped.

The `needs` keyword defines job dependencies and execution order.

## Expected Output

```text
Build Job
    |
    v
Test Job
    |
    v
Deploy Job
```

All three jobs should complete successfully, with green check marks.

## Result

Thus, a GitHub Actions workflow was created with multiple jobs and a defined execution order.
