const
        fi='molecular.inp';
        fo='molecular.out';
var
        a:array ['A'..'Z'] of longint;
        i,m,n,x:longint;
        s,s1:string;
        f:text;
procedure nhap;
begin
        assign(f,fi);
        reset(f);
        readln(f,s);
        a['H']:=1;a['C']:=12;a['N']:=14;a['O']:=16;
        close(f);
end;
procedure xuat;
begin
        assign(f,fo);
        rewrite(f);m:=0;
        repeat
                s1:='';
                while (s[length(s)] in ['0'..'9']) do
                begin
                        s1:=s[length(s)]+s1;
                        delete(s,length(s),1);
                end;
                if s1<>'' then val(s1,n,x)
                else n:=1;
                m:=m+a[s[length(s)]]*n;
                delete(s,length(s),1);
        until length(s)=0;
        write(f,m);
        close(f);
end;
begin
        nhap;
        xuat;
end.
