import pandas as pd

def consecutive_numbers(logs: pd.DataFrame) -> pd.DataFrame:

    # Check whether current number equals previous two numbers
    mask = (
        (logs["num"] == logs["num"].shift(1)) &
        (logs["num"] == logs["num"].shift(2))
    )

    # Get distinct numbers satisfying the condition
    result = logs.loc[mask, "num"].drop_duplicates()

    # Return in required format
    return pd.DataFrame({
        "ConsecutiveNums": result
    })
