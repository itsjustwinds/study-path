var
        s:string;

begin
        readln(s);
        while pos('!',s) <>0 do
        begin
                insert('.',s,pos('!',s));
                delete(s,pos('!',s),1);
        end;
        write(s);
        readln
end.