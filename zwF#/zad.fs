open System

let min(a, b) = 
  if a > b then
    b
  else
    a
    
let max(a, b) = 
  if a > b then
    a
  else
    b

let l1 = [10;11;12;13;14;16;17;18;19;20]
let l2 = [5;6;7;8;9;10;11;12;13;14;15;16;17;18;19;20;21;22;23;24;25]

let srednia = List.append l1 l2 |> List.sum |> fun sum -> float sum / float (List.length l1 + List.length l2)

let f1 = 
  let rnd = Random() 
  l1 @ l2 |> List.sortBy(fun i -> rnd.Next())
  

printfn "%f" srednia
printfn "%A" f1


let f2 = f1 |> List.take 10 

let minEl = f2 |> List.min 
let maxEl = f2 |> List.max


printf "%d\n" minEl
printf "%d" maxEl

//let f3 = l1 l2 ||> List.zip  |> List.map(fun(a,b) -> a + b)

//printf "%A" f3