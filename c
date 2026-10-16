# Experiment C: Run a Workflow for Changes in a Specific Folder

## Aim
To configure a GitHub Actions workflow that runs only when changes are made inside a specified folder.

## Procedure

1. Open your GitHub repository.
2. Select **Add file → Create new file**.
3. Enter the path `.github/workflows/folder-specific.yml`.
4. Paste the following code:

```yaml
name: Folder Specific Workflow

on:
  push:
    branches:
      - main
    paths:
      - 'src/**'

  workflow_dispatch:

jobs:
  folder-job:
    runs-on: ubuntu-latest

    steps:
      - name: Checkout repository
        uses: actions/checkout@v4

      - name: Display message
        run: echo "Changes detected in the src folder"

      - name: List source files
        run: |
          if [ -d src ]; then
            find src -type f
          else
            echo "The src folder does not exist yet."
          fi
```

5. Click **Commit changes** and commit the file to `main`.
6. Create a file inside the `src` folder, such as `src/example.txt`.
7. Commit the change to `main`.
8. Open the **Actions** tab.
9. Select **Folder Specific Workflow** and inspect the run.

## Explanation

The following configuration controls which changes trigger the workflow:

```yaml
paths:
  - 'src/**'
```

It matches changed files anywhere inside the `src` folder, including its subfolders.

- Changes under `src/` can trigger the workflow.
- Changes to unrelated files, such as `README.md`, will not trigger this workflow through the `push` event.
- `workflow_dispatch` allows you to start the workflow manually, even without a change to `src/`.

**Note:** If you want the workflow to run *only* for folder changes, remove the `workflow_dispatch:` line and its associated configuration.

## Expected Result

A push that changes a file under `src/` triggers the workflow. A push that changes only an unrelated file does not trigger it.

## Result

Thus, a GitHub Actions workflow was configured to run automatically based on changes in a specific folder.
