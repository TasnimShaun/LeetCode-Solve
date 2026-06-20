import pandas as pd

def nth_highest_salary(employee: pd.DataFrame, N: int) -> pd.DataFrame:

    # Invalid N
    if N <= 0:
        return pd.DataFrame({
            f'getNthHighestSalary({N})': [None]
        })

    # Get distinct salaries in descending order
    salaries = employee['salary'].drop_duplicates().sort_values(ascending=False)

    # Get Nth highest salary if it exists
    nth_salary = salaries.iloc[N - 1] if len(salaries) >= N else None

    # Return in required format
    return pd.DataFrame({
        f'getNthHighestSalary({N})': [nth_salary]
    })
