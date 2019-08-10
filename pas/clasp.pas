var
        a:array[0..1000001] of longint;
        dd:array[0..1000001] of boolean;
        i,n:longint;
        s:ansistring;
        kq:int64;
procedure nhap;
begin
        readln(n);
        read(s);
        fillchar(dd,sizeof(dd),false);
        for i:=1 to n do
                if s[i]='>' then
                        dd[i]:=true;
end;
procedure xuly;
begin
        fillchar(a,sizeof(a),0);
        for i:=1 to n do
                if dd[i] then a[i]:=a[i-1]+1
                else a[i]:=a[i-1];
        kq:=0;
        for i:=1 to n do
                if dd[i]=false then
                        kq:=kq+a[i];
        write(kq);
end;
begin
        assign(input,'clasp.inp');
        assign(output,'clasp.out');
        reset(input);
        rewrite(output);
        nhap;
        xuly;
        close(input);
        close(output);
end.