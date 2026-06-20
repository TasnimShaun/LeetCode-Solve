import pandas as pd

def duplicate_emails(person: pd.DataFrame) -> pd.DataFrame:

    # Find emails appearing more than once
    result = person.groupby("email").filter(
        lambda x: len(x) > 1
    )

    # Return distinct duplicate emails
    return pd.DataFrame({
        "Email": result["email"].drop_duplicates()
    })
