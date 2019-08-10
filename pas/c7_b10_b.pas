var     s,k:string;
begin
        readln(s);
        while pos('..',s)<>0 do delete(s,pos('..',s),1);
        write(s);
        readln
end.

