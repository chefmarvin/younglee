import { Config } from '../config/config.type';
export default class Frame {
    config: Config;
    counter: number;
    screen: any;
    mainBox: any;
    listtable: any;
    infoBox: any;
    constructor(config: Config);
    init(): void;
    screenWillMount(): void;
    bindings(): void;
    render(): void;
}
