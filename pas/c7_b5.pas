var
        s1,s:string;
        i:longint;
begin
        readln(s);
        s1:=' ';
        for i:=1 to length(s) do
                if s[i]=s1 then delete(s,i,1);
        write(s);
        readln
end.