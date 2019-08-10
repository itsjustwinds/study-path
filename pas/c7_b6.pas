var
        s,s1,s2:string;
        i:longint;
begin   s2:='';s1:='';
        readln(s);
        for i:=1 to length(s) do
        begin
                if s[i]<>' ' then
                        s1:=s1+s[i];

                if (length(s1)>length(s2)) or(s[i]=s[length(s)]) and (s[i]=' ') then s2:=s1;
                if s[i]=' ' then s1:='';
        end;
        write(s2);


readln
end.
