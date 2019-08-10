var
        s:string;
        vt:longint;
begin
        readln(s);
        while pos('xuan',s)<>0 do
        begin   {vt:=pos('xuan',s);
                delete(s,pos('xuan',s),4);  }
                insert('he',s,pos('xuan',s));
                delete(s,pos('xuan',s),4);
        end;
        write(s);
        readln
end.
