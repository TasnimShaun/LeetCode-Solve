import pandas as pd

def order_scores(scores: pd.DataFrame) -> pd.DataFrame:

    # Create dense rank in descending order
    scores["rank"] = scores["score"].rank(
        method="dense",
        ascending=False
    ).astype(int)

    # Sort by score in descending order
    return scores[["score", "rank"]].sort_values(
        by="score",
        ascending=False
    )
