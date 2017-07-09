export class Configs {
    public en: Config;
    public ch: Config;
}

export class Config {
    public name: string;
    public title: string;
    public remoteUrl: string;
    public items: string[][];
    public info: any[];
}
