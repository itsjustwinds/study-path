var
        a:array[1..1000,1..1000] of boolean;
        dd:array[1..1000] of boolean;
        n,m,i,j,x,y,max:longint;
        kq:int64;
procedure nhap;
begin
        fillchar(a,sizeof(a),false);
        readln(n,m);
        for i:=1 to n do
                a[i,i]:=true;
        for i:=1 to m do
        begin
                readln(x,y);
                a[x,y]:=true;
                a[y,x]:=true;
        end;
end;
procedure xuly;
var     i,j,k:longint;
begin
        for k:=1 to n do
                for i:=1 to n do
                        for j:=1 to n do
                        a[i,j]:=a[i,j] or a[k,i] and a[k,j];
        fillchar(dd,sizeof(dd),true);
        kq:=0;
        for i:=1 to n do
                if dd[i] then
                begin
                        max:=0;
                        for j:=1 to n do
                                if a[i,j] then
                                begin
                                        dd[j]:=false;
                                        inc(max);
                                end;
                        if max>kq then kq:=max;
                end;
        write(kq);
end;
begin
        assign(input,'groupmax.inp');
        assign(output,'groupmax.out');
        reset(input);
        rewrite(output);
        nhap;
        xuly;
        close(input);
        close(output);
end.