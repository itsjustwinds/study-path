const
        fi='NUMQUIZ.INP';
        fo='NUMQUIZ.OUT';
var
        a:array [1..100000] of int64;
        n,i:longint;
        tam:int64;
        f:text;
procedure nhap;
begin
        assign(f,fi);
        reset(f);
        readln(f,n);
        for i:=1 to n do
                read(f,a[i]);
        close(f);
end;
function ucln(a,b:int64):longint;
begin
while a <> b do
if a>b then a:=a-b else b:=b-a;
ucln:=a;
        {if a mod b=0 then ucln:=b
        else ucln:=ucln(b,a mod b);}
end;
procedure xuat;
begin
        assign(f,fo);
        rewrite(f);
        tam:={a[1]}0;
        for i:=2 to n do
        begin
               { tam:=ucln(tam,a[i]);
                if tam=1 then break;    }
               if a[i]=0 then inc(tam);
        end;
        write(f,tam{*n});
        close(f);
end;
begin
        nhap;
        xuat;
end.
