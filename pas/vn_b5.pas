var
        s,s1,max:string;
        i:longint;
begin
        readln(s);
        s1:='';
        max:='0';
        for i:=length(s) downto 1 do
                s1:=s1+s[i];
        writeln(s1);
        for i:=1 to length(s) do
                if s[i]>max then max:=s[i];
        write(max);
        readln
end.

