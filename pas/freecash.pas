const
        fi='freecash.inp';
        fo='freecash.out';
var
        a:array [0..23,0..59] of longint;
        x,y,j,i,max,n:longint;
        f:text;
procedure nhap;
begin
        assign(f,fi);
        reset(f);
        readln(f,n);
        fillchar(a,sizeof(a),0);
        for i:=1 to n do
        begin
                readln(f,x,y);
                inc(a[x,y]);
        end;
        close(f);
end;
procedure xuat;
begin
        assign(f,fo);
        rewrite(f);
        max:=0;
        for i:=0 to 23 do
                for j:=0 to 59 do
                        if a[i,j]>max then max:=a[i,j];
        write(f,max);
        close(f);
end;
begin
        nhap;
        xuat;
end.
