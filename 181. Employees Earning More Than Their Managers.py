import pandas as pd

def find_employees(employee: pd.DataFrame) -> pd.DataFrame:

    # Self join employee table with manager information
    merged = employee.merge(
        employee,
        left_on="managerId",
        right_on="id",
        suffixes=("_emp", "_mgr")
    )

    # Employees earning more than their managers
    result = merged[
        merged["salary_emp"] > merged["salary_mgr"]
    ]

    # Return required format
    return pd.DataFrame({
        "Employee": result["name_emp"]
    })
