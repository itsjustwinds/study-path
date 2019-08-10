const
        fi='molecular.inp';
        fo='molecular.out';
var
        a:array['A'..'Z'] of longint;
        s,s1:string;
        n,kq,x:longint;
        f:text;
procedure nhap;
begin
        assign(f,fi);
        reset(f);
        read(f,s);
        a['H']:=1;a['O']:=16;a['N']:=14;a['C']:=12;
        close(f);
end;
procedure xuly;
begin
        assign(f,fo);
        rewrite(f);
        while length(s)<>0 do
        begin
                s1:='';
                while (s[length(s)] in ['0'..'9']) do
                begin
                        s1:=s[length(s)]+s1;
                        delete(s,length(s),1);
                end;
                if s1<>'' then
                begin
                        val(s1,n,x);
                        kq:=kq+n*a[s[length(s)]];
                        delete(s,length(s),1);
                end
                else kq:=kq+a[s[length(s)]];
        end;
        write(f,kq);
        close(f);
end;
begin
        nhap;
        xuly;
end.