   var
        n,i,dem:longint;
   begin
   readln(n); dem:=0;
   for i:=1 to n do
        if n mod i=0 then
                inc(dem);
   while dem<>2 do
   begin
        dem:=0;
        readln(n);
        for i:=1 to n do
                if n mod i=0 then
                        inc(dem);
   end;
   writeln(n);
   readln
  end.

