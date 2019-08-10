var     s,s1:string;
        dem:longint;
begin
        readln(s);
        readln(s1);
        dem:=0;
        while pos(s1,s) <>0 do
        begin
                inc(dem);
                delete(s,pos(s1,s),length(s1));
        end;
        write(dem);
readln
end.