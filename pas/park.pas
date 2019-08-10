const
        fi='park.inp';
        fo='park.out';
var
        a:array [10102010..10109999] of longint;
        b:array [1..1000001] of longint;
        kt:array [10102010..10109999] of boolean;
        i,n,j,k,t:longint;
        f:text;
procedure nhap;
begin
        assign(f,fi);
        reset(f);
        readln(f,n);
        i:=0;
        for j:=1 to n do
        begin
                readln(f,k);
                if kt[k]=false then
                begin
                        inc(i);
                        b[i]:=k;
                        inc(a[k]);
                        kt[k]:=true;
                end
                else
                        inc(a[k]);
        end;
        close(f);
end;
procedure xuly;
begin
        assign(f,fo);
        rewrite(f);
        t:=0;
        for j:=1 to i do
        if a[b[j]]<=5 then
                 t:=t+100
        else
                t:=t+100+a[b[j]]-5;
        write(f,t);
        close(f);
end;
begin
        fillchar(a,sizeof(a),0);
        nhap;
        xuly;
end.