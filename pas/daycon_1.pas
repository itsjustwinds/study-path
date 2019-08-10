const
        fi='daycon.inp';
        fo='daycon.out';
var
        ttt,tth,tht,thh,htt,hth,hht,hhh,i,k:longint;
        s:string;
        f:text;
procedure nhap;
begin
        assign(f,fi);
        reset(f);
        read(f,s);
        close(f);
end;
procedure xuly;
begin
        assign(f,fo);
        rewrite(f);  k:=length(s);
        ttt:=0;tth:=0;tht:=0;thh:=0;htt:=0;hth:=0;hht:=0;hhh:=0;
        for i:=1 to length(s)-2 do
        begin
                if s[i]+s[i+1]+s[i+2]='TTT' then inc(ttt);
                if s[i]+s[i+1]+s[i+2]='TTH' then inc(tth);
                if s[i]+s[i+1]+s[i+2]='THT' then inc(tht);
                if s[i]+s[i+1]+s[i+2]='THH' then inc(thh);
                if s[i]+s[i+1]+s[i+2]='HTT' then inc(htt);
                if s[i]+s[i+1]+s[i+2]='HTH' then inc(hth);
                if s[i]+s[i+1]+s[i+2]='HHT' then inc(hht);
                if s[i]+s[i+1]+s[i+2]='HHH' then inc(hhh);
        end;
        write(f,ttt,' ',tth,' ',tht,' ',thh,' ',htt,' ',hth,' ',hht,' ',hhh);
        close(f);
end;
begin
        nhap;
        xuly;
end.