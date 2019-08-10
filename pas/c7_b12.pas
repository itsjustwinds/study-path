var     s:string;
        i,dem:longint;
begin
        readln(s);
        dem:=0;
        for i:=1 to length(s) do
        if (not (s[i] in ['a'..'z'])) and (not (s[i] in ['A'..'Z'])) then inc(dem);
        write(dem);
        readln
end.

