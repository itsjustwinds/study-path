const
        fi='divisor.inp';
        fo='divisor.out';
var     a:array [1..100000000] of longint;
      {  nt:rray [1..100000000] of boolean;         }
        i,j,n:longint;
        x,kq:int64;
        f,g:text;
{procedure sang;
begin
        fillchar(nt,sizeof(nt),false);
        for i:=2 to maxlongint do
                for j:=2 to trunc(sqrt(i)) do
                        if i mod j=0 then
                        begin
                                nt[i]:=true;
                                break;
                        end;
end;           }
procedure xuat(k:int64);
begin
        fillchar(a,sizeof(a),0);
        i:=2;
        kq:=1;
        while k<>1 do
        begin
                while k mod i=0 do
                begin
                        inc(a[i]);
                        k:=k div i;
                end;
                kq:=kq*(a[i]+1);
                inc(i);
        end;
        writeln(g,kq);
end;
procedure nhap;
begin
        assign(f,fi);
        assign(g,fo);
        reset(f);
        rewrite(g);
        readln(f,n);
        for i:=1 to n do
        begin
                readln(f,x);
                xuat(x);
        end;
        close(f);
        close(g);
end;
begin
        nhap;
end.
