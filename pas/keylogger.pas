var
        s:array[1..1000000] of char;
        res:ansistring;
        i,j,n,vt:longint;
procedure xoa;
begin
        delete(res,vt-1,1);
        dec(vt);
end;
procedure nhap;
begin
        n:=0;
        while not seekeoln do
        begin
                inc(n);
                read(s[n]);
        end;
        vt:=1;
        for i:=1 to n do
        begin
                if s[i]='<' then
                begin
                        if vt>=2 then dec(vt);
                end
                else if s[i]='>' then
                begin
                        if vt<=length(res) then inc(vt);
                end
                else if s[i]='-' then xoa
                else
                begin
                        insert(s[i],res,vt);
                        inc(vt);
                end;
        end;
        writeln(res);
end;
begin
        assign(input,'keylogger.inp');
        assign(output,'keylogger.out');
        reset(input);
        rewrite(output);
        nhap;
        close(input);
        close(output);
end.
