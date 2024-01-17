/*
    從Exact Solution來看的話，當t逼近無限大，則
        expl(-1*pow(Pi,2)*j*DeltaT)*sin(Pi*((i+1)*DeltaX))
    會逼近0
    而u則會逼近 u=x+1
    和 1-(ii)的函式相同

    expl(-1*pow(Pi,2)*j*DeltaT)*sin(Pi*((i+1)*DeltaX))有點像電子訊號中的暫態響應
    在剛發生時對於響應有很大的影響，但隨著時間過去影響力會成指數降低
    最後，響應會逐漸穩定
*/