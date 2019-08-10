var
        s,s1:string;
        i:longint;
begin   s1:='';
        readln(s);
        for i:=length(s) downto 1 do s1:=s1+s[i];
        if s=s1 then write('true')
        else write('false');
        readln
end.