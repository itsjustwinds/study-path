var
        s:string;
        i,dem:longint;
begin
        readln(s);
        s:=s+' ';dem:=0;
        while pos(' ',s)<>0 do
        begin
                inc(dem);
                delete(s,1,pos(' ',s));
        end;
        write(dem);
        readln
end.

