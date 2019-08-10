var
        s:string;
        i:longint;
begin
        readln(s);
        for i:=1 to length(s) do
                if pos(' ',s)<>0 then
                        delete(s,pos(' ',s),1);
        write(s);
        readln
end.